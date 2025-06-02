#!/bin/bash
source ./config.sh

ask_continue() {
    local question="$1"
    read -p "$question (y/n): " answer
    if [[ "$answer" == "y" || "$answer" == "Y" ]]; then
        return 0
    else
        return 1
    fi
}

if [[ ! -f "$APK_PATH" ]]; then
    echo "[!] Error! File $APK_PATH not found!"
    echo "[i] Most likely you did not compile it."
    echo "[i] Use './build.sh --release' to compile and try again."
    exit 1
fi

scp -P $SSH_PORT "$PMBOOTSTRAP_DIR/packages/$CHANNEL/$arch/$APK_NAME" "$SSH_USER@$SSH_HOST:$DIR_SIDELOAD"

ask_continue "Do you want to install the package on the device?"
if [[ $? -ne 0 ]]; then
    echo "Ok, the package will not be installed."
    echo "Use 'apk add $DIR_SIDELOAD/$APK_NAME --allow-untrusted' for manual installation"
    exit 1
fi

ssh -t -p $SSH_PORT "$SSH_USER@$SSH_HOST" "sudo apk add $DIR_SIDELOAD/$APK_NAME --allow-untrusted"
echo "Done"