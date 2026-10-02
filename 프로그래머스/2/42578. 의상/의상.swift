import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict: [String: [String]] = [:]
    for cloth in clothes {
        dict[cloth.last!, default: []].append(cloth.first!)
    }
    
    var result = 1
    dict.keys.forEach { key in
        result *= dict[key]!.count + 1
    }
    result -= 1
    
    return result
}
