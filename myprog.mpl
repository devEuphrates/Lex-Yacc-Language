int a = 100, i = 1, k = 0, l = 0, m = 0;

while i < a + 1 do
    while k < i do
        l = k / 2;
        if l * 2 == k then
            print l + " is an even number.";
            m = m + 1;
        else
            print l + " is an odd number.";
        end
        k = k + 1;
    end
    i = i + 1;
end

if m > 0 then
    print "There are " + m + "even numbers between 0 and " + a;
else
    print "There is no even number between 0 and " + a;
end