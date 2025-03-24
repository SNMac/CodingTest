import Foundation

func solution(_ operations:[String]) -> [Int] {
    var queue = [Int]()
    
    for operation in operations {
        let splitOper = operation.split(separator: " ")
        let oper = splitOper.first!
        let num = Int(splitOper.last!)
        if oper == "I" {
            // 큐에 주어진 숫자 삽입
            queue.append(num!) 
            
        } else {  // oper.first! == "D"
            if num == 1 {
                // 큐에서 최댓값 삭제
                if let max = queue.max() {
                    let index = queue.firstIndex(of: max)!
                    queue.remove(at: index)
                }
                
            } else {
                // 큐에서 최솟값 삭제
                if let min = queue.min() {
                    let index = queue.firstIndex(of: min)!
                    queue.remove(at: index)
                }
            }
        }
    }
    
    if queue.count == 0 {
        return [0, 0]
    }
    
    return [queue.max()!, queue.min()!]
}