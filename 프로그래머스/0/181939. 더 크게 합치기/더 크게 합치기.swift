import Foundation

func solution(_ a:Int, _ b:Int) -> Int {
    var answerAB = Int(String(a) + String(b))!
    var answerBA = Int(String(b) + String(a))!
    
    if answerAB > answerBA {
        return answerAB
    }
    return answerBA
}