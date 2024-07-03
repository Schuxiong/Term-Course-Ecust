var s = [0,1,2,3,4,5,6,7,8];
var e = [1,2,3,8,0,4,7,6,5];
var finalRoad;
var isNineMode = false;
var MODE = 1;
var expandCount = 0;
var S0 = 0;
var TEST_MODE = false;

// 测试用状态
function testData(){
    var data = [[6,1,5,0,2,7,3,8,4],
                [0,8,7,5,3,4,1,2,6],
                [6,3,2,4,5,7,1,0,8],
                [3,8,0,1,4,2,6,7,5],
                [4,1,5,0,3,2,7,6,8],
                [6,7,8,0,3,4,1,2,5],
                [2,1,7,4,8,3,5,0,6],
                [3,4,7,5,6,2,1,8,0],
                [3,8,1,5,0,7,6,2,4],
                [7,8,1,5,6,2,4,3,0]];
    var len = data.length;
    return data[Math.floor(Math.random()*len)];
};

window.onload = function() {
    initial();
}

function initial() {
    if(TEST_MODE) {
        s = testData();
    }
    else{
        s = [0,1,2,3,4,5,6,7,8];
        s.sort(function(){
            return 0.5 - Math.random();
        });
    }
    showInitial(s);
}

document.getElementById("reset8").onclick = function() {
    isNineMode = false;
    MODE = 1;
    initial();
}

document.getElementById("reset9").onclick = function() {
    isNineMode = true;
    MODE = 1;
    initial();
}

document.getElementById("begin8_1").onclick = function() {
    MODE = 1;
    S0 = 0;
    isNineMode = false;
    AStarAlgorithm();
}

document.getElementById("begin8_2").onclick = function() {
    MODE = 2;
    S0 = 0;
    isNineMode = false;
    AStarAlgorithm();
}

document.getElementById("begin9_1").onclick = function() {
    MODE = 1;
    S0 = 0;
    isNineMode = true;
    AStarAlgorithm();
}

document.getElementById("begin9_2").onclick = function() {
    MODE = 2;
    S0 = 0;
    isNineMode = true;
    AStarAlgorithm();
}

function AStarAlgorithm() {
    console.clear();
    var a = new AStar();
    a.setMode(MODE);
    a.init(s, e);
    if(a.getStart().canSolved(a.getEnd())){
        a.AStarAlgorithm();
        a.display(a.getEnd());
        finalRoad = a.getRoad();
        show(0);
    }
    else{
        alert("此状态下无解");
    }
}

function show(i) {
    if(i == 0){
        document.getElementById("result").textContent = "";
        document.getElementById("result").textContent += '总拓展节点数: ' + expandCount + '\n\n';
    }
    if(i < finalRoad.length) {
        if(finalRoad[i].getFValue() > S0) {
            alert("步骤 "+i+" 不满足条件 f(n）≤ f*(S0）");
        }
        if(i >= 1 && MODE == 1 &&
       finalRoad[i-1].getHValue() > 1+finalRoad[i].getHValue()) {
            alert("步骤 "+i+" 不满足条件 h(ni）≤ 1+h(nj）");
        }
        for(var j = 0; j < finalRoad[i].getCodeMap().length; j++) {
            var b = 'pos'+j;
            document.getElementById(b).style.opacity = 1;
            if(!isNineMode && finalRoad[i].getCodeMap()[j] == 0){
                document.getElementById(b).style.opacity = 0;
            }
            else{
                document.getElementById(b).textContent = "" + finalRoad[i].getCodeMap()[j];
            }
        }
        document.getElementById("result").textContent += "步骤 " + i + ':\n';
        document.getElementById("result").textContent += "评估函数值(F): " + finalRoad[i].getFValue() + "\n";
        if(MODE == 1) {
           document.getElementById("result").textContent += "评估函数值(H): " + finalRoad[i].getHValue() + "\n";
        }
        document.getElementById("result").textContent += "估值最小节点:  " + finalRoad[i].getCodeMap().toString() + '\n\n';
        i++;
        setTimeout('show(' + i +')', 250);
    }
}

function showInitial(m) {
    for(var j = 0; j < m.length; j++) {
        var b = 'pos'+j;
        document.getElementById(b).style.opacity = 1;
        if(!isNineMode && m[j] == 0){
            document.getElementById(b).style.opacity = 0;
        }
        else{
            document.getElementById(b).textContent = "" + m[j];
        }
    }
}

// Astar part

// 创建一个优先队列数据结构
function PriorityQueue() {
    var items = [];
    // 向队列尾部添加一个（或多个）新的项
    this.push = function(element){
        if(this.isEmpty()) {
            items.push(element);
        }
        else {
            var flag = false;
            for(var i = 0; i < items.length; i++){
                if(items[i].getFValue() >= element.getFValue()) {
                    items.splice(i, 0, element);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                items.push(element);
            }
        }
    };
    // 移除队列的第一（即排在队列最前面的）项，并返回被移除的元素
    this.pop = function(){
        return items.shift();
    };
    // 返回队列中第一个元素——最先被添加，也将是最先被移除的元素。队列不做任何变动
    this.top = function(){
        return items[0];
    };
    // 如果队列中不包含任何元素，返回 true ，否则返回 false
    this.isEmpty = function(){
        return items.length == 0;
    };
    // 清空队列
    this.clear = function(){
        items = [];
    };
    // 返回队列包含的元素个数，与数组的 length 属性类似
    this.size = function(){
        return items.length;
    };
    this.print = function(){
        console.log(items.toString());
    };
}

function State() {
    var codeMap = [];
    var parent = null;
    var hValue, gValue, fValue, zeroPos;

    this.init = function(code) {
        hValue = gValue = fValue = 0;
        parent = null;
        for(var i = 0; i < code.length; i++) {
            codeMap.push(code[i]);
            if(code[i] == 0){
                zeroPos = i;
            }
        }
    };

    this.initWithState = function(sta) {
        this.init(sta.getCodeMap());
        this.setAllValueWithState(sta);
    };

    this.setParent = function(sta) {
        parent = sta;
    };

    this.setCodeMap = function(code) {
        codeMap = code;
    };

    this.setZeroPos = function(z) {
        zeroPos = z;
    };

    this.setGValue = function(g) {
        gValue = g;
    };

    this.setFValue = function() {
        fValue = gValue + hValue;
    }

    this.getParent = function() {
        return parent;
    };

    this.getFValue = function() {
        return fValue;
    };

    this.getGValue = function() {
        return gValue;
    };

    this.getHValue = function() {
        return hValue;
    };

    this.getCodeMap = function() {
        return codeMap;
    };

    this.getZeroPos = function() {
        return zeroPos;
    };

    this.setHValue1 = function(src) {
        hValue = 0;
        for(var i = 0; i < codeMap.length; i++) {
            if((isNineMode || codeMap[i] != 0) && codeMap[i] == src.getCodeMap()[i]) {
                hValue++;
            }
        }
        hValue = isNineMode? 9 - hValue : 8 - hValue;
    };

    this.setHValue2 = function(src) {
        hValue = 0;
        for(var i = 0; i < codeMap.length; i++) {
            for(var j = 0; j < src.getCodeMap().length; j++) {
                if((isNineMode || codeMap[i] != 0) && codeMap[i] == src.getCodeMap()[j]) {
                    hValue += Math.abs(parseInt((i-j)/3)) + Math.abs(i % 3 - j % 3);
                }
            }
        }
    };

    this.setAllValue = function(src, depth, mode = 1, isSetG = true) {
        if(mode == 1) {
            this.setHValue1(src);
        } else {
            this.setHValue2(src);
        }
        if(isSetG){
            gValue = depth;
        }
        fValue = gValue + hValue;
    };

    this.setAllValueWithState = function(sta) {
        hValue = sta.getHValue();
        gValue = sta.getGValue();
        zeroPos = sta.getZeroPos();
        this.setFValue();
    };

    this.isEqual = function(src) {
        for(var i = 0; i < codeMap.length; i++) {
            if(src.getCodeMap()[i] != codeMap[i]){
                return false;
            }
        }
        return true;
    };

    this.canSolved = function(tar) {
        var res1 = 0, res2 = 0;
        for(var i = codeMap.length-1; i >= 1; i--) {
            for(var j = i-1; j >= 0; j--) {
                if(codeMap[i] != 0 && codeMap[j] != 0
           && codeMap[j] > codeMap[i]) {
                    res1++;
                }
                if(tar.getCodeMap()[i] != 0 && tar.getCodeMap()[j] != 0
           && tar.getCodeMap()[j] > tar.getCodeMap()[i]) {
                    res2++;
                }
            }
        }
        return (res1%2) == (res2%2);
    };

    this.showMap = function() {
        console.log(codeMap);
    }
};

var AStar = function() {
    var OpenTable = [], ClosedTable = [];
    var start = null;
    var end = null;
    var road = [];
    var mode = 1;

    this.init = function(startMap, endMap) {
        start = new State();
        start.init(startMap);
        end = new State();
        end.init(endMap);
    };

    this.isInTable = function(table, src) {
        for(var i = 0; i < table.length; i++) {
            if(table[i].isEqual(src)){
                return i;
            }
        }
        return -1;
    };

    this.setMode = function(m) {
        mode = m;
    };

    this.deleteFromOpenTable = function(src) {
        var i = 0;
        for(i = 0; i < OpenTable.length; i++) {
            if(OpenTable[i].isEqual(src)){
                break;
            }
        }
        OpenTable.splice(i,1);
    };

    this.AStarAlgorithm = function() {
        start.setAllValue(end, 0, mode, true);
        var OpenQueue = new PriorityQueue();
        OpenTable.push(start);
        OpenQueue.push(start);
        var move = [[0,1], [1,0], [0,-1], [-1,0]];
        expandCount = 0;

        while(OpenTable.length > 0) {
            var tmp = OpenQueue.top();
            if(end.isEqual(tmp)) {
                end.setParent(tmp.getParent());
                end.setAllValueWithState(tmp);
                console.log("总扩展节点数：", expandCount);
                S0 = end.getFValue();
                return true;
            }

            OpenQueue.pop();
            ClosedTable.push(tmp);
            this.deleteFromOpenTable(tmp);
            console.log("Open表节点数量：", OpenTable.length);
            console.log("评估值最小节点：", tmp.getCodeMap().toString());
            for(var i = 0; i < 4; i++) {
                var y = tmp.getZeroPos() % 3;
                var x = (tmp.getZeroPos() - y) / 3;
                if(x + move[i][0] < 0 || x + move[i][0] >= 3 ||
                   y + move[i][1] < 0 || y + move[i][1] >= 3) {
                    continue;
                }
                var zPos = (x + move[i][0]) * 3 + (y+move[i][1]);

                if(zPos < 0 || zPos >= tmp.getCodeMap().length) {
                    continue;
                }

                var newState = new State();
                newState.initWithState(tmp);
                var newCodeMap = newState.getCodeMap();
                newCodeMap[tmp.getZeroPos()] = newCodeMap[zPos];
                newCodeMap[zPos] = 0;
                newState.setCodeMap(newCodeMap);
                newState.setParent(tmp);
                newState.setZeroPos(zPos);
                newState.setGValue(tmp.getGValue()+1);

                var flag = this.isInTable(OpenTable, newState);
                var flag0 = this.isInTable(ClosedTable, newState);

                if(flag >= 0) {
                    if(newState.getGValue() < OpenTable[flag].getGValue()){
                        OpenTable[flag].setGValue(newState.getGValue());
                        OpenTable[flag].setParent(newState.getParent());
                        OpenTable[flag].setFValue();
                        newState = null;
                    }
                }
                else if(flag0 >= 0) {
                    if(newState.getGValue() < ClosedTable[flag0].getGValue()){
                        ClosedTable[flag0].setGValue(newState.getGValue());
                        ClosedTable[flag0].setParent(newState.getParent());
                        ClosedTable[flag0].setFValue();
                        newState = null;
                        OpenQueue.push(ClosedTable[flag0]);
                        OpenTable.push(ClosedTable[flag0]);
                        ClosedTable.splice(flag0, 1);
                    }
                }
                else {
                    newState.setAllValue(end, 0, mode, false);
                    OpenQueue.push(newState);
                    OpenTable.push(newState);
                }
                expandCount++;
                if(OpenTable.length >= 15000){
                    alert("该问题有解，但是用此算法无法在有限空间内求解");
                    return false;
                }
            }
        }
        return false;
    };

    this.display = function(p) {
        if(p != null) {
            this.display(p.getParent());
            road.push(p);
        }
    };

    this.getRoad = function() {
        return road;
    }

    this.getStart = function() {
        return start;
    };

    this.getEnd = function() {
        return end;
    };
};