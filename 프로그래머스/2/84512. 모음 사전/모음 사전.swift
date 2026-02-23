import Foundation

func solution(_ word: String) -> Int {    
    var count = 0
    
    let letters = ["A", "E", "I", "O", "U"]
    var visited: [[Bool]] = .init(repeating: [false, false, false, false, false],
                                  count: 5)
    var isFound = false
    func dfs(_ currLetter: String, _ depth: Int, _ index: Int) {
        if isFound { return }
        if depth > 4 { return }
        if visited[depth][index] { return }
        
        count += 1
        let newCurrLetter = currLetter + letters[index]
        if newCurrLetter == word {
            isFound = true
            return
        }
        
        visited[depth][index] = true
        for (index, letter) in letters.enumerated() {
            dfs(newCurrLetter, depth + 1, index)
        }
        visited[depth][index] = false
    }
    
    for i in letters.indices {
        dfs("", 0, i)
    }
    
    return count
}