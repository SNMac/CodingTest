import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var restProgresses: [Int] = []
    for progress in progresses {
        restProgresses.append(100 - progress)
    }
    
    var restDays: [Int] = []
    for (i, rest) in restProgresses.enumerated() {
        var daysToDone = rest / speeds[i]
        if rest % speeds[i] > 0 {
            daysToDone += 1
        }
        restDays.append(daysToDone)
    }
    
    var result: [Int] = []    
    var prevDay = restDays.removeFirst()
    var deployCount = 1
    while !restDays.isEmpty {
        let day = restDays.removeFirst()
        if day <= prevDay {
            deployCount += 1
        } else {
            result.append(deployCount)
            deployCount = 1
            prevDay = day
        }
    }
    result.append(deployCount)
    
    return result
}
