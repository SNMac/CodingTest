import Foundation

func solution(_ word: String) -> Int {
    var count = 0
    var result = 0
    
    let letters = ["A", "E", "I", "O", "U"]
    func dfs(_ currLetter: String) {
        if currLetter == word {
            result = count
            return
        }
        
        if currLetter.count >= 5 { return }
        
        for letter in letters {
            if result != 0 { return }
            count += 1
            dfs(currLetter + letter)
        }
        
    }
    
    dfs("")
    
    return result
}