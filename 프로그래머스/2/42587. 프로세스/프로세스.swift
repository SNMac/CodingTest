import Foundation

func solution(_ priorities: [Int], _ location: Int) -> Int {
    var stack: [(index: Int, priority: Int)] = []
    for (index, i) in priorities.enumerated() {
        stack.append((index, i))
    }
    
    var sortedPriority = priorities.sorted(by: { $0 > $1 })
    
    var executionOrder = 1
    while !stack.isEmpty {
        if stack.first?.index == location && stack.first?.priority == sortedPriority.first {
            return executionOrder
        }
        if stack.first?.priority == sortedPriority.first {
            stack.removeFirst()
            sortedPriority.removeFirst()
            executionOrder += 1
        } else {
            let dequeued = stack.removeFirst()
            stack.append(dequeued)
        }
    }
    return executionOrder
}
