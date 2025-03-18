import Foundation

func solution(_ my_string:String, _ overwrite_string:String, _ s:Int) -> String {
    let rangeStartIndex = my_string.index(my_string.startIndex, offsetBy: s)
    let rangeEndIndex = my_string.index(rangeStartIndex, offsetBy: overwrite_string.count)
    
    var retStr = my_string
    retStr.replaceSubrange(rangeStartIndex..<rangeEndIndex, with: overwrite_string)
    return retStr
}
