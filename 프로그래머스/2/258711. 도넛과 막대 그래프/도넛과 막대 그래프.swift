import Foundation

func solution(_ edges:[[Int]]) -> [Int] {
    /// 간선 딕셔너리 [정점: [outgoing, incoming]]
    var nodesDict = [Int:[Int]]()
    /// [0] = 생성한 정점, [1] = 도넛 그래프 개수, [2] = 막대 그래프 개수, [3] = 8자 그래프 개수
    var answer = [0, 0, 0, 0]
    
    for edge in edges {
        var outgoing = nodesDict[edge[0], default: [0, 0]]
        outgoing[0] += 1
        
        nodesDict[edge[0]] = outgoing
        
        var incoming = nodesDict[edge[1], default: [0, 0]]
        incoming[1] += 1
        nodesDict[edge[1]] = incoming
    }
    
    for node in nodesDict {
        let value = node.value
        let outgoing = value[0]
        let incoming = value[1]
        
        if outgoing > 1 && incoming == 0 {  // 생성한 정점
            answer[0] = node.key
        } else if outgoing > 1 && incoming > 1 {  // 8자 그래프 개수
            answer[3] += 1
        } else if outgoing == 0 {  // 막대 그래프 개수
            answer[2] += 1
        }
    }
    
    let totalGraph = nodesDict[answer[0]]![0]  // 총 그래프 개수 = 생성한 정점의 outgoing 개수
    answer[1] = totalGraph - answer[2] - answer[3]  // 도넛 그래프 개수
    
    return answer
}
