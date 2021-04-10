package kotlinExample

const val PATTERN = "joke"
var rJoke: Int = 0
val jokes = listOf(
    "Two SQL tables sit at the bar. A query approaches and asks Can I join you?",
    "A SQL statement walks into a bar and sees two tables.It approaches, and asks may I join you?",
    "Four engineers get into a car. The car won't start.The Mechanical engineer says It's a broken starter.The Electrical engineer says Dead battery.The Chemical engineer says Impurities in the gasoline.The IT engineer says Hey guys, I have an idea: How about we all get out of the car and get back in.",
    "ASCII silly question, get a silly ANSI.",
    "A byte walks into a bar looking miserable.The bartender asks it: What's wrong buddy?Parity error. it replies. Ah that makes sense, I thought you looked a bit off.",
    "Being a self-taught developer is almost the same as being a cut neck chicken because you have no sense of direction in the beginning.",
    "Programming is 10% science, 20% ingenuity, and 70% getting the ingenuity to work with the science.",
    "UDP is better in the COVID era since it avoids unnecessary handshakes.",
    "A guy walks into a bar and asks for 1.4 root beers.The bartender says I'll have to charge you extra, that's a root beer float.The guy says In that case, better make it a double.",
    "The six stages of debugging:1. That can't happen.2. That doesn't happen on my machine.3. That shouldn't happen.4. Why does that happen?5. Oh, I see.6. How did that ever work?",
    "Knock knock.Who's there?Recursion.Recursion who?Knock knock.",
    "The glass is neither half-full nor half-empty, the glass is twice as big as it needs to be.",
    "There are only 10 kinds of people in this world: those who know binary and those who don't.",
    "Today I learned that changing random stuff until your program works is hacky and a bad coding practice but if you do it fast enough it's Machine Learning and pays 4x your current salary.",
    "If Bill Gates had a dime for every time Windows crashed ... Oh wait, he does.",
    "Two C strings walk into a bar.The bartender asks What can I get ya?The first string says I'll have a gin and tonic.The second string thinks for a minute, then says I'll take a tequila sunriseJF()#JF(#)$(@J#()$@#())!*FNIN!OBN134ufh1ui34hf9813f8h8384h981h3984h5F!##@The first string apologizes, You'll have to excuse my friend, he's not null-terminated.",
    "Java is like Alzheimer's, it starts off slow, but eventually, your memory is gone.",
    "Hey Girl,Roses are #ff0000,Violets are #0000ff,I use hex codes,But I'd use RGB for you.",
    "Can I tell you a TCP joke?Please tell me a TCP joke.OK, I'll tell you a TCP joke.",
    "// This line doesn't actually do anything, but the code stops working when I delete it.",
    "Debugging is like being the detective in a crime movie where you're also the murderer at the same time.",
    "Judge: I sentence you to the maximum punishment...Me (thinking): Please be death, please be death...Judge: Learn Java!Me: Damn.",
    "Debugging: Removing the needles from the haystack.",
    "A programmer puts two glasses on his bedside table before going to sleep.A full one, in case he gets thirsty, and an empty one, in case he doesn't.",
    "The generation of random numbers is too important to be left to chance.",
    "A man is smoking a cigarette and blowing smoke rings into the air. His girlfriend becomes irritated with the smoke and says Can't you see the warning on the cigarette pack? Smoking is hazardous to your health! to which the man replies, I am a programmer.  We don't worry about warnings; we only worry about errors.",
    "I've got a really good UDP joke to tell you but I don’t know if you'll get it.",
    "How do you tell HTML from HTML5?- Try it out in Internet Explorer- Did it work?- No?- It's HTML5.",
    "Java and C were telling jokes. It was C's turn, so he writes something on the wall, points to it and says Do you get the reference? But Java didn't."
)

fun Initialize(): Int { return 1; }
fun StopCommand(): Boolean { return true;}
fun ContainsCommand(str: String) : Boolean { return str.contains(PATTERN, ignoreCase = true)}
fun ExecuteCommand(str: String) : Boolean {
    rJoke = (0..30).random()
    return true
}
fun GetCommandResult() : String? = jokes[rJoke]