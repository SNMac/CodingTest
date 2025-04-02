import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = 0
    var visited = [Bool](repeating: false, count: dungeons.count)
    
    func dfs(currTired: Int, index: Int, count: Int) {
        let consumeTired = dungeons[index].last!
        let afterTired = currTired - consumeTired    
        
        if answer < count {
            answer = count
        }
        
        for i in 0..<dungeons.count {
            let targetMinNeedTired = dungeons[i].first!
            if !visited[i] && afterTired >= targetMinNeedTired {
                visited[i] = true
                dfs(currTired: afterTired, index: i, count: count + 1)
                visited[i] = false
            }
        }
    }
    
    for i in 0..<dungeons.count {
        visited[i] = true
        dfs(currTired: k, index: i, count: 1)
        visited[i] = false
    }
    
    
    return answer
}