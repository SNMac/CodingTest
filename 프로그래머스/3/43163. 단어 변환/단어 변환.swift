import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var answerArr = [Int]()
    var isVisited = [Bool](repeating: false, count: words.count)
    
    if !words.contains(target) {
        return 0
    }
    
    func canTransferable(_ compare1: String, _ compare2: String) -> Bool {
        return zip(compare1, compare2).filter { $0 != $1 }.count == 1
    }
    
    func dfs(currWord: String, step: Int) {
        if currWord == target {
            answerArr.append(step)
            return
        }
        
        for (i, word) in words.enumerated() {
            print("\(currWord), \(word), \(step)")
            
            if !isVisited[i] && canTransferable(currWord, word) {
                isVisited[i] = true
                dfs(currWord: word, step: step + 1)
                
                isVisited[i] = false
            }
        }
    }
    
    dfs(currWord: begin, step: 0)
    
    return answerArr.min()!
}