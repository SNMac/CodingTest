import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var answer = [Int]()
    var lastReleaseDate = 0
    
    for i in 0..<progresses.count {
        let progress = Double(progresses[i])
        let speed = Double(speeds[i])
        let day = Int(ceil((100 - progress) / speed))
        
        if day > lastReleaseDate {
            lastReleaseDate = day
            answer.append(1)
        } else {
            answer[answer.count - 1] += 1
        }
    }
    
    return answer
}