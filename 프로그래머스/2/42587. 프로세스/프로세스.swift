import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var queue: [(Int, Bool)] = []  // (priority, isLocation)
    for (i, priority) in priorities.enumerated() {
        queue.append((priority, i == location))
    }
    
    var executionCount = 1
    while !queue.isEmpty {
        let first = queue.removeFirst()
        if queue.allSatisfy({ $0.0 <= first.0 }) {
            if first.1 {
                break
            } else {
                executionCount += 1
            }
        } else {
            queue.append(first)
        }
    }
    
    return executionCount
}
