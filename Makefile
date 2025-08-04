.PHONY: clean

clean:
	@echo "Borrando todos los archivos .exe..."
	find . -type f -name "*.exe" -exec rm {} +
	@echo "Limpieza completa."