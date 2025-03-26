import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    // index번 노트의 최단경로 간선 개수를 저장하는 배열
    var shortestRouteArr = [Int](repeating: n, count: n + 1)
    var visited = [Bool](repeating: false, count: n + 1)
    var vertexDict = [Int: [Int]]()
    var queue = [(count: 0, currNode: 1)]
    var answer = 0
    
    for vertex in edge {
        if var arr = vertexDict[vertex.first!] {
            arr.append(vertex.last!)
            vertexDict[vertex.first!] = arr
        } else {
            vertexDict[vertex.first!] = [vertex.last!]
        }
        
        if var arr = vertexDict[vertex.last!] {
            arr.append(vertex.first!)
            vertexDict[vertex.last!] = arr
        } else {
            vertexDict[vertex.last!] = [vertex.first!]
        }
    }
    
    while !queue.isEmpty {
        let curr = queue.removeFirst()
        let currCount = curr.count
        let currNode = curr.currNode
        shortestRouteArr[currNode] = currCount
        
        for nextNode in vertexDict[currNode]! {
            if !visited[nextNode] {
                visited[nextNode] = true
                queue.append((count: currCount + 1, currNode: nextNode))
            }
        }
    }
    
    var furthestRoute = 1
    for i in 2..<shortestRouteArr.count {
        if shortestRouteArr[i] == furthestRoute {
            answer += 1
        } else if  shortestRouteArr[i] > furthestRoute {
            furthestRoute = shortestRouteArr[i]
            answer = 1
        }
    }
    
    return answer
}
