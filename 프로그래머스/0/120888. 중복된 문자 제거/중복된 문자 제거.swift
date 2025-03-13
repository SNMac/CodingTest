import Foundation

func solution(_ my_string:String) -> String {
    var charArr: [Character] = []
    
    for char in my_string {
        if !charArr.contains(char) {
            charArr.append(char)
        }
    }
    
    return String(charArr)
}