--[[
     File Name           :     weo.lua
     Created By          :     chroot
     Creation Date       :     [2020-10-12 10:48]
     Last Modified       :     [2020-10-12 11:34]
     Description         :      
--]]
fruts = {"bannanan","orange","apple","ge"}
print(fruts)
for k,v in ipairs(fruts) do
	print(k,v)
end
table.sort(fruts)
for k,v in ipairs(fruts) do
	print(k,v)
end
