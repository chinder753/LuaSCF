local function read_basis_file(file_name)
    assert(type(file_name)=="string")
    local basis_file = io.open(file_name)
    assert(basis_file)
    local basis_string = basis_file:read("a")
    basis_file:close()

    local basis = {}
    for word in string.gmatch(basis_string, "(.-)%*%*%*%*\r*\n") do
        basis[string.match(word, "%a+")] = word
    end

    -- for a, b, c, d in string.gmatch(basis["Cr"], "(%a+) +(%d+) +(%d+%.*%d+)%s([%-*0%.*%d+D%d+%s]+)") do
    for a, b in string.gmatch(basis["Cr"], "%a+ +%d+ +%d+%.*%d+.-") do
        print(a, b)
        print("*****")
    end
end

read_basis_file("sto-3g.txt")
