# Number to english string representation

For example, for the following inputs it should return the following outputs:

-        1  -> one
-        2  -> two
-       10  -> ten
-      100  -> one hundred
-      981  -> nine hundred eighty one
-  8000000  -> eight million()

The program should support both positive and negative integers within the range of a 32-bit std::int32_t integer.

Testing results:

-   -2000000666 -> The equivalent string representation is: "(minus) two billion six hundred sixty six"
-             0 -> The equivalent string representation is: "zero"
-             1 -> The equivalent string representation is: "one"
-      12345678 -> The equivalent string representation is: "twelve million three hundred forty five thousand six hundred seventy eight"
-    -123456789 -> The equivalent string representation is: "(minus) one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine"
-           "a" -> The equivalent string representation is: "zero"
-    "A string" -> The equivalent string representation is: "zero"
