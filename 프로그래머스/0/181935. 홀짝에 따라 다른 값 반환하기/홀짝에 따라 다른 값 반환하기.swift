import Foundation

func solution(_ n:Int) -> Int {
    var arr = [Int](1...n)
    let answer: Int
    if n % 2 == 1 {
        answer = arr
        .filter { $0 % 2 == 1 }
        .reduce(0) { $0 + $1 }
    } else {
        answer = arr
        .filter { $0 % 2 == 0 }
        .map { $0 * $0 }
        .reduce(0) { $0 + $1 }
    }
    
    return answer
}