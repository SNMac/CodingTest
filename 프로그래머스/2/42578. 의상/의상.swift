import Foundation

func solution(_ clothes: [[String]]) -> Int {
    var dict: [String: [String]] = [:]
    
    for cloth in clothes {
        dict[cloth[1], default: []].append(cloth[0])
    }
    
    var combination = 1
    for key in dict.keys {
        // 해당 의상의 종류를 입지 않는 경우 포함 (+ 1)
        let count = dict[key]!.count + 1
        combination *= count
    }
    
    // 모든 의상의 종류를 입지 않는 경우 제외 (- 1)
    combination -= 1
    return combination
}
