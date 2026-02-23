import Foundation

func solution(_ n: Int, _ lost: [Int], _ reserve: [Int]) -> Int {
    var result = 0
    
    var lostStudents = lost
    var reserveStudents = reserve
    for i in 1...n {
        if lostStudents.contains(i) {
            // 체육복을 도난당한 학생
            if reserveStudents.contains(i) {
                // 여분을 가져온 학생인 경우
                reserveStudents.remove(at: reserveStudents.firstIndex(of: i)!)
                lostStudents.remove(at: lostStudents.firstIndex(of: i)!)
            } else if reserveStudents.contains(i - 1) {
                // 앞번호 학생이 여분의 체육복을 가져온 학생인 경우
                reserveStudents.remove(at: reserveStudents.firstIndex(of: i - 1)!)
                lostStudents.remove(at: lostStudents.firstIndex(of: i)!)
            } else if reserveStudents.contains(i + 1) {
                // 뒷번호 학생이 여분의 체육복을 가져온 학생인 경우
                if lostStudents.contains(i + 1) { continue } // 뒷번호 학생이 도난당한 경우 제외
                reserveStudents.remove(at: reserveStudents.firstIndex(of: i + 1)!)
                lostStudents.remove(at: lostStudents.firstIndex(of: i)!)
            } else {
                // 여분이 없고, 앞번호와 뒷번호 학생 모두 여분이 없는 경우
                continue
            }
            result += 1
        } else {
            // 체육복을 도난당하지 않은 학생
            result += 1
        }
    }
    
    return result
}