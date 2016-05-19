let g:cwconv_path = '~/projects/cwconv.git/build/main.exe'
let g:cwconv_path_ms = "C:\projects\cwconv.git\build\main.exe"
nnoremap <silent> <F9> :Cwconv<CR>
command! Cwconv Cwconverter()

function! Cwconverter()
	let argstr = getreg('0')
	if has("win32unix")
		:!cygstart g:cwconv_path argstr
		:<CR>
	elseif has("win32")
		:!g:cwconv_path_ms argstr
		:<CR>
	endif
endfunction
