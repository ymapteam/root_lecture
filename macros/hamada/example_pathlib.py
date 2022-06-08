from pathlib import Path

p = Path('rootfiles')
print(p.is_dir()) # True
print(p.is_file()) # False
print(p.is_absolute()) # False
print(p.resolve()) # /Users/yuto/VS/root_lecture/macros/hamada/rootfiles

data1_path = p / 'data1.root'
print(data1_path.as_posix()) # rootfiles/data1.root
print(data1_path.name) # data1.root
print(data1_path.stem) # data1
print(data1_path.suffix) # .root