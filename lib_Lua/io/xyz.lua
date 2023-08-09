local function read_xyz_file(file_name)
    assert(type(file_name)=="string", table.concat({"input arg error, file name is not a string ", file_name}))

    local xyz_file = io.open(file_name)
    assert(xyz_file, table.concat({"can't open xyz file in ", file_name}))
    local xyz_string = xyz_file:read("a")
    xyz_file:close()

    local xyz_list = string.gmatch(xyz_string, " *(%a+) *(%-?%d+%.*%d+) *(%-?%d+%.*%d+) *(%-?%d+%.*%d+) *\r*\n")
    assert(xyz_list, table.concat({"can't find atom saved in xyz format in ", file_name}))

    local mol = {}
    local index = 0
    for symbol, x, y, z in xyz_list do
        mol[index] = {symbol, tonumber(x), tonumber(y), tonumber(z)}
        index = index + 1
    end
    return mol
end



local function creat_xyz_file(file_name, mol)
    assert(type(file_name)=="string", table.concat({"input arg error, file name is not a string ", file_name}))

    local xyz_file = io.open(file_name, "w")
    assert(xyz_file, table.concat({"can't open xyz file ", file_name}))

    xyz_file:write(#mol, "\n\n")
    local num_line = 2
    while num_line < #mol do
        assert(mol[num_line][1], table.concat({"xyz content information error in line ", num_line}))
        assert(mol[num_line][2], table.concat({"xyz content information error in line ", num_line}))
        assert(mol[num_line][3], table.concat({"xyz content information error in line ", num_line}))
        assert(mol[num_line][4], table.concat({"xyz content information error in line ", num_line}))
        xyz_file:write(string.format("%s %15f %15f %15f\n", mol[num_line][1], mol[num_line][2], mol[num_line][3], mol[num_line][4]))
        num_line = num_line + 1
    end
    xyz_file:close()
end

local mol = read_xyz_file("test/Untitled.xyz")
creat_xyz_file("test.xyz", mol)