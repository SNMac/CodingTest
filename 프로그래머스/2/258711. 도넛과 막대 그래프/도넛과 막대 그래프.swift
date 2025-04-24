import Foundation

func solution(_ edges:[[Int]]) -> [Int] {
    /// 간선 배열 [정점: [outgoing, incoming]]
    var nodes = [Int:[Int]]()
    /// [0] = 생성, [1] = 도넛, [2] = 막대, [3] = 8자
    var answer = [0, 0, 0, 0]
    
    for edge in edges {
        var outgoing = nodes[edge[0], default: [0, 0]]
        outgoing[0] += 1
        
        nodes[edge[0]] = outgoing
        
        var incoming = nodes[edge[1], default: [0, 0]]
        incoming[1] += 1
        nodes[edge[1]] = incoming
    }
    
    for node in nodes {
        let value = node.value
        let outgoint = value[0]
        let incoming = value[1]
        
        if outgoint > 1 && incoming == 0 {  // 생성
            answer[0] = node.key
        } else if outgoint > 1 && incoming > 1 {  // 8자
            answer[3] += 1
        } else if outgoint == 0 {  // 막대
            answer[2] += 1
        }
    }
    
    let graph = nodes[answer[0]]![0]  // 생성한 정점의 outgoing 개수
    answer[1] = graph - answer[2] - answer[3]
    
    return answer
}