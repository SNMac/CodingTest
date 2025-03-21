import Foundation

func solution(_ my_string:String, _ k:Int) -> String {
    var answer = ""
    
    for i in 0..<k {
        answer += my_string
    }
    
    return answer
}