import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict = [String: [String]]()
    var answer = 1
    
    for cloth in clothes {
        guard var clothArr = dict[cloth.last!] else {
            dict[cloth.last!] = [cloth.first!]
            continue
        }
        clothArr.append(cloth.first!)
        dict[cloth.last!] = clothArr
    }
    
    // 옷 종류마다 "입지 않음" 이라는 옷이 추가로 있다고 생각
    for clothType in dict.keys {
        // "입지 않음" 이라는 옷 추가해서 개수 세기
        answer *= dict[clothType]!.count + 1
    }
    
    // 모두 "입지 않음" 옷만 입은 경우 빼기
    answer -= 1
    
    return answer
}
