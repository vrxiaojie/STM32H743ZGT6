import os
import glob
import xml.etree.ElementTree as ET
import argparse

def indent(elem, level=0):
    """ Helper function to indent the XML for pretty printing. """
    i = "\n" + level * "    "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "    "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            indent(elem, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i
        if not elem.tail:
            elem.tail = "\n"

def add_files_to_group(uvprojx_file_path, folder_path, group_name_target):
    # 改变文件扩展名从 .uvprojx 到 .xml
    base, ext = os.path.splitext(uvprojx_file_path)
    if ext != '.uvprojx':
        print("The input file does not have the .uvprojx extension.")
        return
    
    xml_path = base + '.xml'
    os.rename(uvprojx_file_path, xml_path)

    try:
        # 解析XML文件
        tree = ET.parse(xml_path)
        root = tree.getroot()

        # 找到指定GroupName的Group节点
        target_group = None
        for group in root.findall('.//Group'):
            group_name = group.find('GroupName')
            if group_name is not None and group_name.text == group_name_target:
                target_group = group
                break

        if target_group is None:
            print(f"No Group with GroupName '{group_name_target}' found in the XML structure.")
            # 将文件扩展名改回 .uvprojx
            os.rename(xml_path, uvprojx_file_path)
            return

        # 找到目标 Group 节点下的 Files 节点，如果不存在则创建一个
        files_node = target_group.find('Files')
        if files_node is None:
            files_node = ET.SubElement(target_group, 'Files')

        # 遍历指定文件夹，查找所有 .c 和 .h 文件
        for subdir, _, files in os.walk(folder_path):
            for file in files:
                if file.endswith('.c') or file.endswith('.h'):
                    # 计算相对路径
                    file_path = os.path.relpath(os.path.join(subdir, file), start=os.path.dirname(xml_path))

                    # 创建 File 节点并添加到 Files 节点下
                    file_node = ET.SubElement(files_node, 'File')
                    file_name_node = ET.SubElement(file_node, 'FileName')
                    file_name_node.text = file
                    file_type_node = ET.SubElement(file_node, 'FileType')
                    if file.endswith('.c'):
                        file_type_node.text = '1'  # .c 文件类型都为 1
                    elif file.endswith('.h'):
                        file_type_node.text = '5'  # .h 文件类型都为 5
                    file_path_node = ET.SubElement(file_node, 'FilePath')
                    file_path_node.text = file_path

        # 格式化 XML
        indent(root)

        # 保存修改后的 XML 文件
        tree.write(xml_path, encoding='utf-8', xml_declaration=True)
        print("Files added successfully.")

    except ET.ParseError as e:
        print(f"ParseError: {e}")
        with open(xml_path, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            start = max(0, e.position[0] - 5)
            end = min(len(lines), e.position[0] + 5)
            print("Context around the error:")
            for i in range(start, end):
                print(f"{i+1}: {lines[i].strip()}")

    finally:
        # 将文件扩展名改回 .uvprojx
        os.rename(xml_path, uvprojx_file_path)

def find_uvprojx_file():
    uvprojx_files = glob.glob("*.uvprojx")
    if not uvprojx_files:
        print("No .uvprojx file found in the current directory.")
        return None
    elif len(uvprojx_files) > 1:
        print("Multiple .uvprojx files found in the current directory:")
        for i, file in enumerate(uvprojx_files, start=1):
            print(f"{i}. {file}")
        print("Please ensure there is only one .uvprojx file in the directory.")
        return None
    else:
        return uvprojx_files[0]

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Add .c and .h files to a specific group in a .uvprojx file.")
    parser.add_argument("folder_path", help="Relative path to the folder containing .c and .h files to be added.")
    parser.add_argument("group_name", help="Name of the group to add the files to.")
    args = parser.parse_args()

    uvprojx_file_path = find_uvprojx_file()
    if uvprojx_file_path:
        add_files_to_group(uvprojx_file_path, args.folder_path, args.group_name)
