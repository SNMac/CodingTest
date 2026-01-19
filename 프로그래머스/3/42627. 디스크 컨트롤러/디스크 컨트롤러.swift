import Foundation

struct Heap<T: Comparable> {
    var heap: [T] = []
    
    init() {}
    init (data: T) {
        heap.append(data)
        heap.append(data)
    }
}

extension Heap {
    mutating func insert(_ data: T) {
        if heap.isEmpty {
            heap.append(data)
            heap.append(data)
            return
        }
        
        heap.append(data)
        
        func isMovingUp(_ insertIndex: Int) -> Bool {
            if insertIndex <= 1 {
                return false
            }
            let parentIndex = insertIndex / 2
            return heap[insertIndex] < heap[parentIndex] ? true : false
        }
        
        var insertIndex = heap.count - 1
        while isMovingUp(insertIndex) {
            let parentIndex = insertIndex / 2
            heap.swapAt(insertIndex, parentIndex)
            insertIndex = parentIndex
        }
    }
    
    mutating func pop() -> T? {
        if heap.count <= 1 { return nil }
        
        let returnData = heap[1]
        heap.swapAt(1, heap.count - 1)
        heap.removeLast()
        
        func swapIfNeeded(_ index: Int) {
            let leftChildIndex = index * 2
            let rightChildIndex = leftChildIndex + 1
            
            let hasNoChild = heap.count <= leftChildIndex
            if hasNoChild { return }
            
            let hasOnlyLeftChild = heap.count <= rightChildIndex
            if hasOnlyLeftChild {
                if heap[index] > heap[leftChildIndex] {
                    heap.swapAt(index, leftChildIndex)
                    swapIfNeeded(leftChildIndex)
                    return
                } else {
                    return
                }
            }
            
            if heap[leftChildIndex] < heap[rightChildIndex] && heap[leftChildIndex] < heap[index] {
                heap.swapAt(leftChildIndex, index)
                swapIfNeeded(leftChildIndex)
                return
            } else if heap[rightChildIndex] < heap[leftChildIndex] && heap[rightChildIndex] < heap[index] {
                heap.swapAt(rightChildIndex, index)
                swapIfNeeded(rightChildIndex)
                return
            } else {
                return
            }
        }
        
        swapIfNeeded(1)
        
        return returnData
    }
}

struct Job: Comparable {
    static func < (lhs: Job, rhs: Job) -> Bool {
        return lhs.executionTime < rhs.executionTime ? true : false
    }
    
    let index: Int
    let requestedTime: Int
    let executionTime: Int
}


func solution(_ jobs: [[Int]]) -> Int {
    var remainJobs = jobs
    
    var totalTurnaroundTime = 0
    var currentTime = 0
    while !remainJobs.isEmpty {
        var heap: Heap<Job> = Heap()
        for (index, job) in remainJobs.enumerated() {
            if job[0] <= currentTime {
                heap.insert(Job(index: index, requestedTime: job[0], executionTime: job[1]))
            }
        }
        
        if let executingJob = heap.pop() {
            let turnaroundTime = currentTime - executingJob.requestedTime + executingJob.executionTime
            totalTurnaroundTime += turnaroundTime
            currentTime += executingJob.executionTime
            remainJobs.remove(at: executingJob.index)
        } else {
            currentTime += 1
        }
    }
    
    let averageTurnaroundTime = totalTurnaroundTime / jobs.count
    return averageTurnaroundTime
}
