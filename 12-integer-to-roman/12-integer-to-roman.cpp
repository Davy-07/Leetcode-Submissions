class Solution {
public:
    string intToRoman(int num) {
        
        string roman = "";
        map<int, string> symbol;
        
        symbol.insert({ 1, "I" });
        symbol.insert({ 5, "V" });
        symbol.insert({ 10, "X" });
        symbol.insert({ 50, "L" });
        symbol.insert({ 100, "C" });
        symbol.insert({ 500, "D" });
        symbol.insert({ 1000, "M" });
        
        int digit, units = 0, power;
        while (num) {
            digit = num % 10;
            num = num / 10;
            power = pow(10, units);
            
            if (digit == 4) 
                roman = symbol[power] + symbol[5 * power] + roman;
            else if (digit == 9)
                roman = symbol[power] + symbol[10 * power] + roman;
            else if (digit == 5)
                roman = symbol[5 * power] + roman;
            else if (digit != 0) {
                string x = digit > 5 ? symbol[5 * power] : "";
                digit = digit % 5;
                while (digit--) x += symbol[power];
                roman = x + roman;
            }
            units++;
        }
                      
        return roman;
    }
};