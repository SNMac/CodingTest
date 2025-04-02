import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = 0
    var visited = [Bool](repeating: false, count: dungeons.count)
    
    func dfs(currTired: Int, count: Int) {  
        if answer < count {
            answer = count
        }
        
        for i in 0..<dungeons.count {
            let targetMinNeedTired = dungeons[i][0]
            let consumeTired = dungeons[i][1]
            
            if !visited[i] && currTired >= targetMinNeedTired {
                visited[i] = true
                dfs(currTired: currTired - consumeTired, count: count + 1)
                visited[i] = false
            }
        }
    }
    
    dfs(currTired: k, count: 0)    
    
    return answer
}