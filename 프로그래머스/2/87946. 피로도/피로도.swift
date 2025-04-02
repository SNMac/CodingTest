import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = [Int]()
    var visited = [Bool](repeating: false, count: dungeons.count)
    
    func dfs(tired: Int, index: Int, count: Int) {
        let minNeedTired = dungeons[index].first!
        let consumeTired = dungeons[index].last!
        
        if tired < minNeedTired {
            answer.append(count - 1)
            return
        }
        
        if count == dungeons.count {
            answer.append(count)
            return
        }
        
        let currTired = tired - consumeTired
        
        for i in 0..<dungeons.count {
            
            if !visited[i] {
                visited[i] = true
                dfs(tired: currTired, index: i, count: count + 1)
                visited[i] = false
            }
        }
    }
    
    for i in 0..<dungeons.count {
        visited[i] = true
        dfs(tired: k, index: i, count: 1)
        visited[i] = false
    }
    
    
    return answer.max()!
}