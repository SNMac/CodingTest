import Foundation

func solution(_ babbling:[String]) -> Int {
    let pronounciation = ["aya", "ye", "woo", "ma"]
    var answer = 0
    
    for i in 0..<babbling.count {
        var babb = babbling[i]
        for j in 0..<4 {
            // replacingOccurrences 사용 X
            if let range = babb.range(of: pronounciation[j]) {
                babb.replaceSubrange(range, with: " ")
            }                
        }
        
        // replacingOccurrences 사용
        babb = babb.replacingOccurrences(of: " ", with: "")
        if babb.isEmpty {
            answer += 1
        }
    }
    print("answer: \(answer)")
    return answer
}