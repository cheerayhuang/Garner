import os
import subprocess
import platform 

versions = ["RB-8.4.3", "RB-8.4.4", "RB-8.4.5", "RB-9.1.0", "RB-9.2.0"]
#versions       = ["RB-8.4.4"]
cubrid_svn_url = "http://svn.bds.nhncorp.com/xdbms/cubrid/branches/"
cms_svn_url    = "http://svn.bds.nhncorp.com/xdbms/cubrid-manager/branches/"
home           = os.getcwd()


def svn_checkout_code(version):
	p1 = subprocess.Popen(["svn", "checkout", cubrid_svn_url+version, "cubrid-"+version])
	p2 = subprocess.Popen(["svn", "checkout", cms_svn_url+version+"/server", "CMS-"+version])
	p1.wait()
	p2.wait()

def get_platform():
	
	if platform.machine() == "x86" :
		return "win32"
	if platform.machine() == "AMD64":
		return "x64"
		
def check_cubrid_build_num():
	
	p          = subprocess.Popen(["svn", "info", "BUILD_NUMBER"], stdout=subprocess.PIPE)
	(out, err) = p.communicate()
	out_list   = out.rsplit("\r\n");
	
	for i in out_list:
		if i.find(r"Last Changed Rev: ") != -1 :
			build_num = i.replace(r"Last Changed Rev: ", r"")
			break
			
	p = subprocess.Popen(["svn", "update", "-r", build_num])
	p.wait()

	p = subprocess.Popen(["type", "BUILD_NUMBER"], shell=True, stdout=subprocess.PIPE)
	(build_ver, err) = p.communicate()

	return build_ver.strip("\r\n")

def deploy_cubrid(plat): 
	
	src_path = os.getcwd()+r"\install\cubrid_Release_"+plat
	os.chdir(home+r"\cubrid")
	p = subprocess.Popen(["xcopy", src_path, "/e", "/y"])
	p.wait()
	
def build_cubrid(ver, plat):
	
	os.chdir(os.getcwd()+r"\cubrid-"+ver)
	build_ver = check_cubrid_build_num()
	print build_ver
	
	os.chdir(os.getcwd()+r"\win")
	vs_cmd = os.getenv("VS90COMNTOOLS")+r"..\IDE\devenv.com"
	print vs_cmd
	
	p = subprocess.Popen([vs_cmd, "cubrid.sln", "/build", "Release|win32", "/project", "gencat"])
	p.wait()
	if p.returncode != 0 :
		print "build cubrid failed!"
		exit(1)
		
	p = subprocess.Popen([vs_cmd, "cubrid.sln", "/build", "Release|"+plat])
	p.wait()
	if p.returncode != 0 :
		print "build cubrid failed!"
		exit(1)
	
	p = subprocess.Popen([vs_cmd, "cubrid_client.sln", "/build", "Release|"+plat])
	p.wait()
	if p.returncode != 0 :
		print "build cubrid failed!"
		exit(1)
		
	p = subprocess.Popen([vs_cmd, "cubrid_compat.sln", "/build", "Release|"+plat])
	p.wait()
	if p.returncode != 0 :
		print "build cubrid failed!"
		exit(1)
		
	p = subprocess.Popen([vs_cmd, "cubrid_dbgw.sln", "/build", "Release|"+plat])
	p.wait()
	if p.returncode != 0 :
		print "build cubrid failed!"
		exit(1)
		
	deploy_cubrid(plat)
	
	os.chdir(home)
	return build_ver


def build_CMS(ver, plat):
	
	cubrid_path = os.getcwd()+r"\cubrid"
	os.chdir(os.getcwd()+"\\"+ver+r"\CMS-"+ver)
	cms_path = os.getcwd()+r"\build"

	if plat == "x64":
		prefix_plat = r"--enable-64bit"

	p = subprocess.Popen(["build.bat", r"--prefix="+cms_path, prefix_plat, "--with-cubrid-dir="+cubrid_path], shell=True)
	p.wait()
	if p.returncode != 0 :
		print "build CMS failed!"
		exit(1)

	os.chdir(home)

def package_CMS(version, platform, build_ver): 

	os.chdir(os.getcwd()+"\\"+version+r"\CMS-"+version+r"\build")

	print os.getcwd()

	zip_file = r"CUBRID_Manager_Server-"+build_ver+r"-windows-"+platform+r".zip"
	p = subprocess.Popen(["7z", "a", zip_file])
	p.wait()

	dst_path = home + r"\cms_builds"
	p        = subprocess.Popen(["xcopy", zip_file, dst_path, "/y"])
	p.wait()

	os.chdir(home)

def main():

	for version in versions: 
		print os.getcwd()
		os.chdir(os.getcwd()+"\\"+version)
		svn_checkout_code(version)
		
		if os.path.exists(os.getcwd()+r"\..\cubrid"):
			p = subprocess.Popen(["rd", "/q", "/s", os.getcwd()+r"\..\cubrid"], shell=True) 
			p.wait()
			
		if os.path.exists(os.getcwd()+r"\CMS-"+version+r"\build") :
			p = subprocess.Popen(["rd", "/q", "/s", os.getcwd()+r"\CMS-"+version+r"\build"], shell=True)
			p.wait()
		
		subprocess.Popen(["md", os.getcwd()+r"\..\cubrid"], shell=True)
		subprocess.Popen(["md", os.getcwd()+r"\CMS-"+version+r"\build"], shell=True)
		
		platform  = get_platform()
		build_ver = build_cubrid(version, platform) 
		build_CMS(version, platform)
		package_CMS(version, platform, build_ver)


if __name__ == "__main__":
	main()
	
