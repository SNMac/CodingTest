import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var answer = [Int]()
    var etaArr = [Int]()
    
    for i in 0..<progresses.count {
        let remainProgress = 100 - progresses[i]
        if remainProgress % speeds[i] > 0 {
            etaArr.append(remainProgress / speeds[i] + 1)
        } else {
            etaArr.append(remainProgress / speeds[i])
        }
    }
    
    while !etaArr.isEmpty {
        var finished = 0
        
        for i in 0..<etaArr.count {
            etaArr[i] -= 1
        }
        
        while let first = etaArr.first {
            if first <= 0 {
                finished += 1
                etaArr.removeFirst()
            } else {
                break
            }
        }
        
        if finished > 0 {
            answer.append(finished)
        }
    }
    
    return answer
}