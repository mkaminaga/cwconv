let g:cwconv_path = '~/projects/cwconv.git/build/main.exe'
let g:cwconv_path_ms = "C:\projects\cwconv.git\build\main.exe"
nnoremap <silent> <F9> :Cwconv<CR>
command! Cwconv :call Cwconverter()

function! Cwconverter()
	let argstr = getreg('0')
	if has("win32unix")
		:echo(join([expand(g:cwconv_path),expand(argstr)]))
	elseif has("win32")
		:!<C-=>expand(g:cwconv_path_ms) <C-=>expand(argstr)
	endif
endfunction
