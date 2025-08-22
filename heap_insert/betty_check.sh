#!/bin/bash

# Betty Style Checker Script
# This script checks if the code follows Betty coding standards

echo "🔍 BETTY STYLE CHECK"
echo "=================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to check Betty style
check_betty() {
    local file=$1
    echo -n "Checking $file... "
    
    if command -v betty &> /dev/null; then
        if betty "$file" &> /dev/null; then
            echo -e "${GREEN}✅ PASSED${NC}"
            return 0
        else
            echo -e "${RED}❌ FAILED${NC}"
            betty "$file"
            return 1
        fi
    else
        echo -e "${YELLOW}⚠️  Betty not installed${NC}"
        return 0
    fi
}

# Function for manual style verification
manual_check() {
    local file=$1
    echo "Manual checks for $file:"
    
    # Check for trailing whitespace
    if grep -q '[[:space:]]$' "$file"; then
        echo -e "${RED}  ❌ Trailing whitespace found${NC}"
    else
        echo -e "${GREEN}  ✅ No trailing whitespace${NC}"
    fi
    
    # Check for tabs
    if grep -q $'\t' "$file"; then
        echo -e "${RED}  ❌ Tabs found (should use spaces)${NC}"
    else
        echo -e "${GREEN}  ✅ No tabs found${NC}"
    fi
    
    # Check line length (should be <= 80 characters)
    local long_lines=$(awk 'length > 80 {print NR": " $0}' "$file")
    if [ -n "$long_lines" ]; then
        echo -e "${RED}  ❌ Lines longer than 80 characters:${NC}"
        echo "$long_lines"
    else
        echo -e "${GREEN}  ✅ All lines <= 80 characters${NC}"
    fi
    
    # Check for proper function spacing
    local func_spacing=$(grep -n '^{$' "$file")
    if [ -n "$func_spacing" ]; then
        echo -e "${RED}  ❌ Opening braces should be on same line${NC}"
        echo "$func_spacing"
    else
        echo -e "${GREEN}  ✅ Proper brace placement${NC}"
    fi
}

# Main execution
echo "Checking C source files..."
echo

files=(
    "0-binary_tree_node.c"
    "1-heap_insert.c"
    "binary_tree_print.c"
    "binary_trees.h"
)

failed_files=0

for file in "${files[@]}"; do
    if [ -f "$file" ]; then
        echo "📁 $file"
        echo "--------"
        
        if ! check_betty "$file"; then
            failed_files=$((failed_files + 1))
        fi
        
        manual_check "$file"
        echo
    else
        echo -e "${YELLOW}⚠️  $file not found${NC}"
    fi
done

echo "📊 SUMMARY"
echo "=========="
if [ $failed_files -eq 0 ]; then
    echo -e "${GREEN}🎉 All files passed Betty style check!${NC}"
else
    echo -e "${RED}💥 $failed_files file(s) failed Betty style check${NC}"
fi

echo
echo "🔧 BETTY STYLE REMINDERS:"
echo "• Use spaces, not tabs"
echo "• Max 80 characters per line"
echo "• Opening braces on same line"
echo "• No trailing whitespace"
echo "• Proper function documentation"
echo "• No more than 5 functions per file"
