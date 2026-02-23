import Foundation

func solution(_ k: Int, _ dungeons: [[Int]]) -> Int {
    var result = 0
    
    var visited: [Bool] = .init(repeating: false, count: dungeons.count)
    func dfs(_ fatigue: Int, _ index: Int, _ travelled: Int) {        
        if visited[index] { return }
        
        let dungeon = dungeons[index]
        if dungeon[0] > fatigue { return }
        
        result = max(result, travelled + 1)
        
        visited[index] = true
        let newFatigue = fatigue - dungeon[1]
        for i in dungeons.indices {
            dfs(newFatigue, i, travelled + 1)
        }
        visited[index] = false
    }
    
    for i in dungeons.indices {
        dfs(k, i, 0)
    }
    
    return result
}