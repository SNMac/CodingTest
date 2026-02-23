import Foundation

func solution(_ n: Int, _ lost: [Int], _ reserve: [Int]) -> Int {
    var actualLost: [Int] = Set(lost).subtracting(reserve).sorted()
    var actualReserve: Set<Int> = Set(reserve).subtracting(lost)
    
    var actualLostCount = actualLost.count
    for student in actualLost {
        if actualReserve.contains(student - 1) {
            actualReserve.remove(student - 1)
            actualLostCount -= 1
        } else if actualReserve.contains(student + 1) {
            actualReserve.remove(student + 1)
            actualLostCount -= 1
        } else {
            continue
        }
        
    }
    
    return n - actualLostCount
}