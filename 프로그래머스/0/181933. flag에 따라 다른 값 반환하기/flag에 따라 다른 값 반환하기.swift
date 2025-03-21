import Foundation

func solution(_ a:Int, _ b:Int, _ flag:Bool) -> Int {
    if flag {
        return a + b
    }
    
    return a - b
}