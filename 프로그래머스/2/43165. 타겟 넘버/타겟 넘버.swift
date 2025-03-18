import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var answer = 0
    
    func dfs(_ index: Int, _ currCalc: Int) {
        if index == numbers.count {
            if currCalc == target {
                answer += 1
            }
            return
        }
        dfs(index + 1, currCalc + numbers[index])
        dfs(index + 1, currCalc - numbers[index])
    }
    
    dfs(0, 0)
    
    return answer
}