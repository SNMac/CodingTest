import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    // index번 노트의 최단경로 간선 개수를 저장하는 배열
    var shortestRouteArr = [Int](repeating: 0, count: n + 1)
    var visited = [Bool](repeating: false, count: n + 1)
    var vertexDict = [Int: [Int]]()
    var queue: [(currNode: Int, count: Int)] = []
    var answer = 0
    
    // 딕셔너리에 간선 양방향으로 추가
    for vertex in edge {
        if vertexDict[vertex.first!] != nil {
            vertexDict[vertex.first!]?.append(vertex.last!)
        } else {
            vertexDict[vertex.first!] = [vertex.last!]
        }
        
        if vertexDict[vertex.last!] != nil {
            vertexDict[vertex.last!]?.append(vertex.first!)
        } else {
            vertexDict[vertex.last!] = [vertex.first!]
        }
    }
    
    // BFS
    queue.append((currNode: 1, count: 0))
    visited[1] = true
    while !queue.isEmpty {
        let curr = queue.removeFirst()
        let currCount = curr.count
        let currNode = curr.currNode
        shortestRouteArr[currNode] = currCount
        
        for nextNode in vertexDict[currNode]! {
            if !visited[nextNode] {
                visited[nextNode] = true
                queue.append((currNode: nextNode, count: currCount + 1))
            }
        }
    }
    
    // 가장 먼 노드 개수 세기
    let furthestRoute = shortestRouteArr.max()
    answer = shortestRouteArr.filter { $0 == furthestRoute }.count
    
    return answer
}
