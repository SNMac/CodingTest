import Foundation

func solution(_ operations:[String]) -> [Int] {
    var queue = [Int]()
    
    for operation in operations {
        let splited = operation.split(separator: " ")
        let oper = splited.first!
        let num = Int(splited.last!)!
        
        if oper == "I" {
            // 큐에 주어진 숫자 삽입
            queue.append(num)
        } else {  // oper == "D"
            if num == 1 {
                // 큐에서 최댓값 삭제
                queue.sort(by: <)
                queue.popLast()
            } else if num == -1 {
                // 큐에서 최솟값 삭제
                queue.sort(by: >)
                queue.popLast()
            }
        }
    }
    
    let max = queue.max() ?? 0
    let min = queue.min() ?? 0
    
    return [max, min]
}
