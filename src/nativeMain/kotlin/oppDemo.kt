package opplibdemo
class Clazz {
    fun memberFunction(p: Int): ULong = 42UL
    fun craigMethodGreeting(): String {
        return "Aloha, from Craig.  This is inside a Kotlin class"
    }
}

fun forIntegers(b: Byte, s: Short, i: UInt, l: Long) { }
fun forFloats(f: Float, d: Double) { }

fun strings(str: String) : String? {
    return "That is '$str' from C"
}

val globalString = "A global String"