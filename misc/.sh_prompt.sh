function getGitBranch()
{
    branch=$(git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\ \1/')

    if [ "$branch" == "" ]; then
        echo " none"
    else
        echo "$branch"
    fi
}

PS1="\[\033[0;32m\]|\[\033[0m\033[0;32m\]\u\[\033[0m\]@\[\033[0;36m\]\h\[\033[0m\033[0;32m\]|\[\033[0m\]\t\[\033[0;32m\]|\[\033[1;31m\]\w\[\033[0;32m\]|\[\033[0;33m\]\$(getGitBranch) \[\033[0;32m\]|\n\[\033[0;32m\]└┼─\[\033[0m\033[0;32m\]\$\[\033[0m\033[0;32m\]─┤▶\[\033[0m\]"
