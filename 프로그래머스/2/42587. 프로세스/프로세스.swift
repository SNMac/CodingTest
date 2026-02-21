import Foundation

func solution(_ priorities: [Int], _ location: Int) -> Int {
    var localPriorities = priorities
    var queue: [(priority: Int, isTarget: Bool)] = []
    
    for (index, priority) in priorities.enumerated() {
        if index == location {
            queue.append((priority, true))
        } else {
            queue.append((priority, false))
        }
    }
    
    var times = 0
    while !queue.isEmpty {
        let maxPriority = localPriorities.max()
        while queue.first!.priority != maxPriority {
            let first = queue.removeFirst()
            queue.append(first)
        }
        
        times += 1
        let deleteIndex = localPriorities.firstIndex(of: maxPriority!)
        localPriorities.remove(at: deleteIndex!)
        let executed = queue.removeFirst()
        if executed.isTarget {
            return times
        }
    }
    
    return times
}
