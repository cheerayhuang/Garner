# 使用quick-x-server全服排行榜

标签（空格分隔）： quick-x-server quick-cocos2d-x ranklist 排行榜

[toc]

---

##0 介绍

quick-x-server的排行榜服务，是一个基于websocket的服务， 数据交换格式采用标准json。

##1 从一个例子开始

1. 利用C:\Users\ck01-\Desktop\quick-cocos2d-x-master\samples\websockets\scripts下的WebSockets.lua这个库。

2. 根据调用的api需求创建json格式，并调用lua的json库将其encode为字符串。  
    ```lua
    local table = {
        "action":"RankList.add", 
        "key": "PlayerName", 
        "value": "99.5"
    }

    data = json.encode(table) 
    ```

3. 利用WebSockets:Send(data, MessageType) 发送请求。

    其中，MessageType = WebSockets.TEXT_MESSAGE。
    ```lua
    WebSockets:Send(data, WebSockets.TEXT_MESSAGE)
    ```

4. 利用回调函数WebSockets:OnMessage(event) 处理返回来的结果。

##2 基本JSON结构

基本的json结构为： 

``` json
{
    "action": "RankList.xxx", 
    "param1": "value1", 
    "param2": "value2", 
    ...
    "paramN": "valueN"
}
```

比如将一个玩家的分数插入全服排行榜

那么该http请求的body部分为： 

```json
{
    "action":"RankList.Add", 
    "key": "PlayerName", 
    "value": "99.5"
}
```

##3 排行榜API

###3.1 RankList.Count 
* 获取排行榜的大小（排行榜的玩家总数）
* Request json 
```json
{
    "action":"RankList.Count"
}
```
  
* Response json
```json
{
    "success": 1, 
    "count": xxxx  // 排行榜的大小
}
```
  
###3.2 RankList.Add
* 添加玩家分数进入排行榜
* Resquest json 
```json
{
    "action":"RankList.Add", 
    "key": "xxxx",  // 玩家ID
    "value": "xxxx"   // 玩家分数
}
```

* Response json 
```json
{
    "success": 1
}
```

###3.3 RankList.Remove
* 删除一个玩家的数据
* Request json
```json
{
    "action":"RankList.Remove", 
    "key": "xxxx"   // 玩家ID
}
```
* Response json 
```json
{
    "success": 1
}
```
###3.4 RankList.Score
* 获取一个玩家的分数
* Request json
```json
{
    "action":"RankList.Score", 
    "key": "xxxx"   // 玩家ID
}
```
* Response json 
```json
{
    "success": 1,
    "score": xxxx // 玩家分数
}
```
###3.5 RankList.GetScoreRange
* 获取一个分段内的所有玩家数据
* Request json
```json
{
    "action":"RankList.GetScoreRange", 
    "lower_bound": "xxxx",   // 区间的左端点
    "upper_bound": "xxxx"    // 区间的右端点
}
```
* Response json 
```json
{
    "success": 1， 
    "list" : {                          // 返回的这一区间内的数据
        "Palyer Id" : "Player Score",   // 玩家ID以及玩家分数
        ...
    }
}
```

###3.6 RankList.GetRank
* 获取一个玩家的排名
* Request json
```json
{
    "action":"RankList.GetRank", 
    "key": "xxxx"   // 玩家ID
}
```
* Response json 
```json
{
    "success": 1，
    "rank": xxxx  // 玩家排名
}
```

###3.7 RankList.GetRevRank
* 获取一个玩家的倒序排名
* Request json
```json
{
    "action":"RankList.GetRevRank", 
    "key": "xxxx"   // 玩家ID
}
```
* Response json 
```json
{
    "success": 1
    "rev_rank": xxxx  // 玩家倒序排名
}
```
###3.8 RankList.GetRankRange
* 获取一个排名区间内的所有玩家数据
* Request json
```json
{
    "action":"RankList.GetRankRange", 
    "lower_bound": "xxxx",   // 排名区间的左端点
    "upper_bound": "xxxx"    // 排名区间的右端点
}
```
* Response json 
```json
{
    "success": 1， 
    "list": {                       // 返回这一排名区间的数据
        "playerId": "player score"  // 玩家id 以及 玩家的分数
    }
}
```
###3.9 RankList.GetRevRankRange
* 获取一个倒序排名区间内的所有玩家的数据， 比如倒数前三名。
* Request json
```json
{
    "action":"RankList.GetRevRankRange", 
    "lower_bound": "xxxx",   // 倒序的排名区间的左端点
    "upper_bound": "xxxx"    // 倒序的排名区间的右端点
}
```
* Response json 
```json
{
    "success": 1， 
    "list": {                       // 返回这一排名区间的数据
        "playerId": "player score"  // 玩家id 以及 玩家的分数
    }
}
```

###3.10 RankList.Limit
* 从排行榜末端删除数据，直到满足所限制的大小。
* Request json
```json
{
    "action":"RankList.Limit", 
    "count": "xxxx"   // 限制排行榜的大小
}
```
* Response json 
```json
{
    "success": 1
}
```

###3.11 RankList.RevLimit
* 从排行榜头部删除数据，直到满足所限制的大小。与Limit删除数据的方向相反。
* Request json
```json
{
    "action":"RankList.RevLimit", 
    "count": "xxxx"   // 限制排行榜的大小
}
```
* Response json 
```json
{
    "success": 1
}
```

