import Foundation

func solution(_ s:String) -> Bool
{
    var stack: [Character] = []
    
    for c in s {
        if c == ")" {
            if stack.isEmpty {
                return false
            }
            stack.removeLast()
            
        } else {
            stack.append(c)
        }
    }
    
    if stack.isEmpty {
        return true
    }
    return false
}
