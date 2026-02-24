import Foundation

func solution(_ numbers: [Int], _ target: Int) -> Int {
    var result = 0
    
    func dfs(_ currCalc: Int, _ index: Int) {
        if index == numbers.count {
            if currCalc == target { result += 1 }
            return
        }
        
        dfs(currCalc + numbers[index], index + 1)
        dfs(currCalc - numbers[index], index + 1)
    }
    
    dfs(0, 0)
    
    return result
}