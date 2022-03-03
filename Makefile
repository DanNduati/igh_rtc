BINARY_NAME = rtc-test
PARTICLE_CLI = particle
DEVICE_TYPE = boron
FIRMWARE = $(BINARY_NAME)-$(DEVICE_TYPE).bin


.PHONY: all install flash clean  enter-dfu-mode

$(FIRMWARE):
	$(PARTICLE_CLI) compile $(DEVICE_TYPE) . --saveTo $(FIRMWARE)

## Build the firmware and flash it via USB
flash: $(FIRMWARE) enter-dfu-mode 
	$(PARTICLE_CLI) flash --usb $(FIRMWARE)

## Enter DFU mode on the attached USB device
enter-dfu-mode: 
	$(PARTICLE_CLI) usb dfu

serial:
	$(PARTICLE_CLI) serial monitor

## Delete all firmware builds
clean: 
	rm -f *.bin