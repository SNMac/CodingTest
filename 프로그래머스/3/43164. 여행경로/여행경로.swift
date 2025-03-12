import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    // 행선지를 기준으로 알파벳 오름차순으로 정렬
    let sortedTickets = tickets.sorted { $0[1] < $1[1] }
    // 방문 기록
    var visited = [Bool](repeating: false, count: sortedTickets.count)
    // 정답
    var answer: [String] = []
    
    func dfs(startAirport: String) {
        // 정답에 저장된 공항 개수 == 항공권 개수 => startAirport가 마지막 공항
        if answer.count == sortedTickets.count {
            answer.append(startAirport)
            return
        }
        
        for i in 0..<sortedTickets.count {
            if !visited[i] && sortedTickets[i][0] == startAirport {
                visited[i] = true
                answer.append(startAirport)
                dfs(startAirport: sortedTickets[i][1])
                
                // 정답(여행 경로) 원소 개수 == 항공권 개수 + 1
                if answer.count == sortedTickets.count + 1 {
                    return
                }
                
                // 정답이 아닐 때
                answer.removeLast()
                visited[i] = false
            }
        }
        
    }
    
    dfs(startAirport: "ICN")
    
    return answer
}