import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    // 양방향 간선 배열
    var connection = [[Int]](repeating: [Int](), count: n + 1)  // index: 출발 노드, value: 도착 노드
    var visited = [Bool](repeating: false, count: n + 1)
    var answerDic = [Int: Int]()  // key: 도착 노드, value: 1번 노드로부터 최단 거리
    
    // 배열에 간선 양방향으로 추가
    for vertex in edge {
        connection[vertex.first!].append(vertex.last!)
        connection[vertex.last!].append(vertex.first!)
    }
    
    // BFS 시작
    var currNodes = Set<Int>([1])  // 출발 노드를 담는 Set
    var currDist = 1  // 1번 노드로부터의 거리
    
    while !currNodes.isEmpty {
        var nodes = Set<Int>()  // 도착 노드를 담는 Set
        for node in currNodes {
            visited[node] = true
            
            for connectedNode in connection[node] {  // 모든 연결된 노드에 대해 반복
                if !visited[connectedNode] {
                    visited[connectedNode] = true
                    answerDic[connectedNode] = currDist
                    nodes.insert(connectedNode)
                }
            }
        }
        
        currDist += 1
        currNodes = nodes
    }
    
    let max = answerDic.values.max()
    return answerDic.filter { $0.value == max }.count
}

