import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var isVisited = [Bool](repeating: false, count: words.count)
    var queue = [(step: 0, currWord: begin)]
    
    func canConvertable(_ compare1: String, _ compare2: String) -> Bool {
        return zip(compare1, compare2).filter { $0 != $1 }.count == 1
    }
    
    if !words.contains(target) {
        return 0
    }
    
    while !queue.isEmpty {
        let curr = queue.removeFirst()
        let currStep = curr.step
        let currWord = curr.currWord
        if currWord == target {
            return currStep
        }
        
        for (i, word) in words.enumerated() {
            if !isVisited[i] && canConvertable(currWord, word) {
                isVisited[i] = true
                queue.append((step: currStep + 1, currWord: word))
            }
        }
    }
    
    return 0
}